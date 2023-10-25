package cards

sealed trait Suit
case object Clubs extends Suit
case object Diamonds extends Suit
case object Hearts extends Suit
case object Spades extends Suit

sealed trait Value
case object Ace extends Value
case object Two extends Value
case object Three extends Value
case object Four extends Value
case object Five extends Value
case object Six extends Value
case object Seven extends Value
case object Eight extends Value
case object Nine extends Value
case object Ten extends Value

sealed trait Face
case object Jack extends Face
case object Queen extends Face
case object King extends Face

case class Card(suit: Suit, value: Value, face:Face)

