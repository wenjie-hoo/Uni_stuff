package orders
import pizzeria._

case class Order(
                  name: String,
                  address: String,
                  phone: String,
                  pizzas: Seq[Pizza],
                  drinks: Seq[Drink.Drink],
                  discount: Option[String] = None,
                  specialInfo: Option[String] = None
                ) {
  private val phoneRegex = """\d{2}-\d{3}-\d{3}-\d{3}"""
  require(phone.matches(phoneRegex), s"Invalid phone number: $phone")

  override def toString() =
    s"$name's order:\n" +
      s"Phone Number: $phone\n"+
      s"Pizzas:\n${pizzas.map(_.toString).mkString("\n")}\n" +
      s"Drinks: ${drinks.map(_.toString).mkString(", ")}\n" +
      s"specialInfo: ${specialInfo.getOrElse("N/A")}"

  def extraMeatPrice: Double = pizzas.map(_.extraMeatPrice).sum
  def drinksPrice: Double = drinks.map(_.price).sum

  val totalPrice: Double = {
    val pizzasTotal = pizzas.map(_.price).sum *
      (discount match {
        case Some("student") => 0.95
        case Some("senior") => 0.93
        case _ => 1.0
      })
    val drinksTotal = drinksPrice *
      (discount match {
        case Some("senior") => 0.93
        case _ => 1.0
      })
    pizzasTotal + drinksTotal
  }
}
