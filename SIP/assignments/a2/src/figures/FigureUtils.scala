package figures
import numbers.Rational

class Point(val x: Rational, val y: Rational)

sealed trait Figure {
  def area: Rational
  val description: String
}

object Figure {
  def areaSum(figures: List[Figure]): Rational = {
    var sum: Rational = Rational(0)
    for (figure <- figures) {
      sum += figure.area
    }
    sum
  }

  def printAll(figures: List[{val description: String}]): Unit = {
    figures.foreach(f => println(f.description))
  }
}

object FiguresApp extends App {
  val p1 = new Point(Rational(0), Rational(0))
  val p2 = new Point(Rational(5), Rational(0))
  val p3 = new Point(Rational(0), Rational(5))
  val p4 = new Point(Rational(5), Rational(5))
  val triangle = new Triangle(p1, p2, p3)
  val rectangle = new Rectangle(p1, p2, p3, p4)
  val square = new Square(p1, p2, p3, p4)

  val figures = List(triangle, rectangle, square)
  Figure.printAll(figures)
  println("Total area: " + Figure.areaSum(figures))
}

class Triangle(val p1: Point, val p2: Point, val p3: Point) extends Figure {
  def area: Rational = {
    val a = p1.x * (p2.y - p3.y)
    val b = p2.x * (p3.y - p1.y)
    val c = p3.x * (p1.y - p2.y)
    val d = a+b+c
    d / Rational(2)
  }
  val description: String = "Triangle"
}

class Rectangle(val p1: Point, val p2: Point, val p3: Point, val p4: Point)  extends Figure{
  def area: Rational = {
    val w = (p2.x - p1.x)
    val h = (p3.y - p1.y)
    (w * h)
  }
  val description: String = "Rectangle"
}

class Square(p1: Point, p2: Point, p3: Point,p4: Point) extends Rectangle(p1,p2,p3,p4) {
  override val description = " Square "
}




