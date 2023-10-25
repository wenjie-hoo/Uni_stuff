package numbers

class Rational (n: Int, d: Int) {
  require(d != 0, "Denominator cannot be zero")

  private val gcdVal = gcd(n.abs, d.abs)
  val numerator: Int = n / gcdVal
  val denominator: Int = d / gcdVal

  def +(other: Rational): Rational = {
    val num = numerator * other.denominator + other.numerator * denominator
    val den = denominator * other.denominator
    Rational(num, den)
  }

  def -(other: Rational): Rational = this + Rational(-other.numerator, other.denominator)

  def *(other: Rational): Rational = {
    val num = numerator * other.numerator
    val den = denominator * other.denominator
    Rational(num, den)
  }

  def /(other: Rational): Rational = this * Rational(other.denominator, other.numerator)

  override def toString: String = {
    val whole = numerator / denominator
    val remainder = numerator % denominator
    if (remainder == 0) {
      s"$whole"
    } else {
      s"$whole $remainder / $denominator"
    }
  }

  private def gcd(a: Int, b: Int): Int = {
    if (b == 0) a else gcd(b, a % b)
  }
}

object Rational {
  def apply(numerator: Int): Rational = new Rational(numerator, 1)
  def apply(numerator: Int, denominator: Int): Rational = new Rational(numerator, denominator)

//  val Zero = Rational(0)
//  val One = Rational(1)
}
