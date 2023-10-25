import pizzeria._
import orders._

object Main {
  def main(args: Array[String]): Unit = {
    val margarita = Pizza(PizzaType.Margarita, PizzaSize.Regular, PizzaCrust.Thin, None, Some(PizzaTopping.Ketchup))
    val pepperoni = Pizza(PizzaType.Pepperoni, PizzaSize.Large, PizzaCrust.Thick, Some(PizzaMeat.Salami),Some(PizzaTopping.Ketchup))
    val funghi = Pizza(PizzaType.Funghi, PizzaSize.Small, PizzaCrust.Thick,None, Some(PizzaTopping.Garlic))
    val order = Order(
      "Jack",
      "Kredka 69",
      "48-352-123-423",
      List(margarita, pepperoni, funghi),
      List(Drink.Lemonade),
      Some("student"),
      Some("black pepper and salt")
    )
    println(order)
    println(f"Total price: ${order.totalPrice}%.2f")
  }
}