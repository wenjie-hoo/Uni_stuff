import figures._
import numbers._

val p1 = new Point(Rational(0), Rational(0))
val p2 = new Point(Rational(3), Rational(0))
val p3 = new Point(Rational(0), Rational(4))

val p4 = new Point(Rational(3), Rational(4))
val p5 = new Point(Rational(0), Rational(3))
val p6 = new Point(Rational(3), Rational(3))

val triangle = new Triangle(p1, p2, p3)
val rectangle = new Rectangle(p1, p2, p3, p4)
val square = new Square(p1, p2, p3, p4)

println(s"${triangle.description} area: ${triangle.area}")
println(s"${rectangle.description} area: ${rectangle.area}")
println(s"${square.description} area: ${square.area}")
