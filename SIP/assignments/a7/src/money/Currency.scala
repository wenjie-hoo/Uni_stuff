package money

sealed trait Currency
case object USD extends Currency
case object EUR extends Currency
case object PLN extends Currency

val conversion: Map[(Currency, Currency), BigDecimal] = Map(
  (EUR, PLN) -> 4.57,
  (EUR, USD) -> 1.10,
  (PLN, USD) -> 0.24,
  (PLN, EUR) -> 0.21,
  (USD, EUR) -> 0.90,
  (USD, PLN) -> 4.14
)

case class CurrencyConverter(conversion: Map[(Currency, Currency), BigDecimal]) {
  def convert(from: Currency, to: Currency): BigDecimal = {
    if (from == to) 1.0
    else conversion.getOrElse((from, to), 1 / conversion((to, from)))
  }
}

case class Money(amount: BigDecimal, currency: Currency)(implicit currencyConverter: CurrencyConverter) {
  def +(other: Money): Money = {
    val convertedAmount = currencyConverter.convert(other.currency, currency) * other.amount
    Money(amount + convertedAmount, currency)
  }

  def -(other: Money): Money = {
    val convertedAmount = currencyConverter.convert(other.currency, currency) * other.amount
    Money(amount - convertedAmount, currency)
  }

  def *(scalar: BigDecimal): Money = {
    Money(amount * scalar, currency)
  }

  def as(targetCurrency: Currency): Money = {
    val convertedAmount = currencyConverter.convert(currency, targetCurrency) * amount
    Money(convertedAmount, targetCurrency)
  }
  def >(other: Money): Boolean = {
    val convertedAmount = currencyConverter.convert(other.currency, currency) * other.amount
    amount > convertedAmount
  }
  def <(other: Money): Boolean ={
    val convertedAmount = currencyConverter.convert(other.currency, currency) * other.amount
    amount < convertedAmount
  }
}

object Money {
  implicit val currencyConverter: CurrencyConverter = CurrencyConverter(conversion)
  def apply(amount: BigDecimal)(currency: Currency): Money = {
    Money(amount, currency)
  }
}
