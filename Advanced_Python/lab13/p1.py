from sqlalchemy import create_engine, Column, Integer, String, DateTime, ForeignKey, and_, or_
from sqlalchemy.orm import declarative_base, relationship, validates
from sqlalchemy.orm.session import sessionmaker
import argparse
from secrets import username, password, host

engine = create_engine(f'mysql+mysqlconnector://{username}:{password}@{host}/python')
Base = declarative_base()

class Event(Base):
    __tablename__ = 'events'
    id = Column(Integer, primary_key=True)
    start_time = Column(DateTime)
    end_time = Column(DateTime)
    description = Column(String(100))
    event_type_id = Column(Integer, ForeignKey('event_types.id'))
    attendees = relationship('EventAttendees', backref='event_attendees')

    @validates('start_time', 'end_time')
    def validate_time(self, key, value):
        new_start = self.start_time
        new_end = self.end_time

        if key == 'start_time':
            new_start = value
        elif key == 'end_time':
            new_end = value

        if new_start and new_end:
            overlapping_event = session.query(Event).filter(
                Event.id != self.id,
                and_(
                    Event.start_time < new_end,
                    Event.end_time > new_start
                )
            ).first()
            assert overlapping_event is None, "Event time is clashed"
        return value

class Attendee(Base):
    __tablename__ = 'attendees'
    id = Column(Integer, primary_key=True)
    name = Column(String(100))
    email = Column(String(100))

class EventTypes(Base):
    __tablename__ = 'event_types'
    id = Column(Integer, primary_key=True)
    name = Column(String(100))
    events = relationship('Event', backref='event_types')

class EventAttendees(Base):
    __tablename__ = 'event_attendees'
    id = Column(Integer, primary_key=True)
    event_id = Column(Integer, ForeignKey('events.id'))
    attendee_id = Column(Integer, ForeignKey('attendees.id'))

Base.metadata.create_all(engine)
Session = sessionmaker(bind=engine)
session = Session()


def read_data(table):
    if table == 'events':
        data = session.query(Event).all()
    elif table == 'attendees':
        data = session.query(Attendee).all()
    elif table == 'event_types':
        data = session.query(EventTypes).all()
    elif table == 'event_attendees':
        data = session.query(EventAttendees).all()
    else:
        print(f"Table '{table}' not found.")
        return
    print(f"\nData in '{table}' table:")
    for item in data:
        print(item.__dict__)



parser = argparse.ArgumentParser()

# parser
parser = argparse.ArgumentParser(description="Manage events and attendees")
subparsers = parser.add_subparsers(dest='command')

# create
add_parser = subparsers.add_parser('add', help='Add a new entry')
add_parser.add_argument('table', help='Name of table to add new entry to')
add_parser.add_argument('--values', required=False, nargs='+', help='Pairs of initial columns and values')

# delete
delete_parser = subparsers.add_parser('delete', help='Delete an existing entry')
delete_parser.add_argument('table', help='Name of table to delete entry from')
delete_parser.add_argument('--ids', required=False, nargs='+', help='IDs of entry to delete')
delete_parser.add_argument('--values', required=False, nargs='+', help='Pairs of column with values to delete')

# update
update_parser = subparsers.add_parser('update', help='Update an existing entry')
update_parser.add_argument('table', help='Name of table to update entry in')
update_parser.add_argument('--ids', required=False, nargs='+', help='IDs of entry to update')
update_parser.add_argument('--values', required=False, nargs='+', help='Pairs of column and value to update from')
update_parser.add_argument('--newvalues', required=True, nargs='+', help='Pairs of column and value to update to')

# read
read_parser = subparsers.add_parser('read', help='Read and display data from a table')
read_parser.add_argument('table', help='Name of table to read')

# Parse the arguments
args = parser.parse_args()

if args.command == 'add':
    new_entry = None
    if(args.table == 'events'):
        new_entry = Event()
    elif(args.table == 'attendees'):
        new_entry = Attendee()
    elif(args.table == 'event_types'):
        new_entry = EventTypes()
    elif(args.table == 'event_attendees'):
        new_entry = EventAttendees()

    if(args.values):
        if(len(args.values) % 2 != 0):
            parser.error("Values must be in pairs")

        columns = args.values[::2]
        values = args.values[1::2]
        for i in range(len(columns)):
            setattr(new_entry, columns[i], values[i])

    session.add(new_entry)
    session.commit()

elif args.command == 'delete':
    entries = []
    if(args.ids):
        if(args.table == 'events'):
            entries += session.query(Event).filter(Event.id.in_(args.ids)).all()
        elif(args.table == 'attendees'):
            entries += session.query(Attendee).filter(Attendee.id.in_(args.ids)).all()
        elif(args.table == 'event_types'):
            entries += session.query(EventTypes).filter(EventTypes.id.in_(args.ids)).all()
        elif(args.table == 'event_attendees'):
            entries += session.query(EventAttendees).filter(EventAttendees.id.in_(args.ids)).all()

    if(args.values):
        if(len(args.values) % 2 != 0):
            parser.error("Values must be in pairs")

        columns = args.values[::2]
        values = args.values[1::2]

        if(args.table == 'events'):
            for i in range(len(columns)):
                entries += session.query(Event).filter(getattr(Event, columns[i]) == values[i]).all()
        elif(args.table == 'attendees'):
            for i in range(len(columns)):
                entries += session.query(Attendee).filter(getattr(Attendee, columns[i]) == values[i]).all()
        elif(args.table == 'event_types'):
            for i in range(len(columns)):
                entries += session.query(EventTypes).filter(getattr(EventTypes, columns[i]) == values[i]).all()
        elif(args.table == 'event_attendees'):
            for i in range(len(columns)):
                entries += session.query(EventAttendees).filter(getattr(EventAttendees, columns[i]) == values[i]).all()

    for entry in entries:
        session.delete(entry)
    session.commit()

elif args.command == 'update':
    entries = []
    if(args.ids):
        if(args.table == 'events'):
            entries += session.query(Event).filter(Event.id.in_(args.ids)).all()
        elif(args.table == 'attendees'):
            entries += session.query(Attendee).filter(Attendee.id.in_(args.ids)).all()
        elif(args.table == 'event_types'):
            entries += session.query(EventTypes).filter(EventTypes.id.in_(args.ids)).all()
        elif(args.table == 'event_attendees'):
            entries += session.query(EventAttendees).filter(EventAttendees.id.in_(args.ids)).all()

    if(args.values):
        if(len(args.values) % 2 != 0):
            parser.error("Values must be in pairs")
            
        columns = args.values[::2]
        values = args.values[1::2]

        if(args.table == 'events'):
            for i in range(len(columns)):
                entries += session.query(Event).filter(getattr(Event, columns[i]) == values[i]).all()
        elif(args.table == 'attendees'):
            for i in range(len(columns)):
                entries += session.query(Attendee).filter(getattr(Attendee, columns[i]) == values[i]).all()
        elif(args.table == 'event_types'):
            for i in range(len(columns)):
                entries += session.query(EventTypes).filter(getattr(EventTypes, columns[i]) == values[i]).all()
        elif(args.table == 'event_attendees'):
            for i in range(len(columns)):
                entries += session.query(EventAttendees).filter(getattr(EventAttendees, columns[i]) == values[i]).all()

    for entry in entries:
        columns = args.newvalues[::2]
        values = args.newvalues[1::2]
        for i in range(len(columns)):
            setattr(entry, columns[i], values[i])
            
    session.commit()

elif args.command == 'read':
    read_data(args.table)

session.close()

"""
python p1.py add attendees --values name 'a1' email 'a1@e.com'
python p1.py add event_types --values id 1 name 't1'

python p1.py delete attendees --values name a1
python p1.py delete event_types --values id 1 

python p1.py add events --values start_time '2023-12-12 12:00:00' end_time '2023-12-12 14:00:00' description 'math' event_type_id 1
python p1.py add events --values start_time '2023-12-12 14:00:00' end_time '2023-12-12 16:00:00' description 'english' event_type_id 2
python p1.py add events --values start_time '2023-12-12 14:00:00' end_time '2023-12-12 16:00:00' description 'python' event_type_id 3

python p1.py add events --values start_time '2023-12-22 12:00:00' end_time '2023-12-22 14:00:00' description 'math' name 't1'
python p1.py delete events --values id 3

python p1.py add event_attendees --values event_id 1 attendee_id 1

example of reading a table and it returns
❯ python p1.py read events;
Data in 'events' table:
{'_sa_instance_state': <sqlalchemy.orm.state.InstanceState object at 0x7f77c58000a0>, 'start_time': datetime.datetime(2023, 12, 12, 12, 0), 'end_time': datetime.datetime(2023, 12, 12, 14, 0), 'event_type_id': 1, 'description': 'math', 'id': 1}
{'_sa_instance_state': <sqlalchemy.orm.state.InstanceState object at 0x7f77c5800520>, 'start_time': datetime.datetime(2023, 12, 12, 14, 0), 'end_time': datetime.datetime(2023, 12, 12, 16, 0), 'event_type_id': 2, 'description': 'english', 'id': 4}
"""