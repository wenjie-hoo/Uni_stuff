//
//package money
//
//object Currency {
//  sealed trait Currency
//  case object USD extends Currency
//  case object EUR extends Currency
//  case object PLN extends Currency
//
//  case class Money(value: Double, currency: Currency) {
//    def +(other: Money):a Money = Money(convert(other.currency, currency, other.value) + value, currency)
//    def -(other: Money): Money = Money(value - convert(other.currency, currency, other.value), currency)
//    def *(multiplier: Double): Money = Money(value * multiplier, currency)
//    def as(targetCurrency: Currency): Money = Money(convert(currency, targetCurrency, value), targetCurrency)
//    def >(other: Money): Boolean = value > convert(other.currency, currency, other.value)
//    def <(other: Money): Boolean = value < convert(other.currency, currency, other.value)
//  }
//
//  implicit class DoubleOps(value: Double) {
//    def apply(currency: Currency): Money = Money(value, currency)
//  }
//
//  private def convert(from: Currency, to: Currency, value: Double): Double = {
//    val conversionRate = (from, to) match {
//      case (USD, EUR) => 0.90
//      case (USD, PLN) => 3.83
//      case (EUR, USD) => 1.22
//      case (EUR, PLN) => 4.69
//      case (PLN, USD) => 0.26
//      case (PLN, EUR) => 0.21
//      case _ => 1.0
//    }
//    value * conversionRate
//  }
//}
//
