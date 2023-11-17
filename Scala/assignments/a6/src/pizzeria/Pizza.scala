package pizzeria
import pizzeria.Drink.Lemonade

object PizzaType {
  sealed trait Type { val price: Double }
  case object Margarita extends Type { val price = 5 }
  case object Pepperoni extends Type { val price = 6.5 }
  case object Funghi extends Type { val price = 7 }
}

object PizzaSize {
  sealed trait Size { val factor: Double }
  case object Small extends Size { val factor = 0.9 }
  case object Regular extends Size { val factor = 1 }
  case object Large extends Size { val factor = 1.5 }
}

object PizzaCrust {
  sealed trait Crust
  case object Thin extends Crust {val factor = 1}
  case object Thick extends Crust {val factor = 1}
}

object PizzaTopping {
  sealed trait Topping { val price: Double }
  case object Ketchup extends Topping { val price = 0.5 }
  case object Garlic extends Topping { val price = 0.5 }
}

object PizzaMeat {
  sealed trait Meat { val price: Double }
  case object Salami extends Meat { val price = 1 }
}

object Drink {
  sealed trait Drink { val price: Double }
  case object Lemonade extends Drink { val price = 2 }
}

case class Pizza(
                  pizzaType: PizzaType.Type,
                  size: PizzaSize.Size,
                  crust: PizzaCrust.Crust,
                  extraMeat: Option[PizzaMeat.Meat] = None,
                  extraTopping: Option[PizzaTopping.Topping] = None
                ){
  override def toString() =
    s"${size.toString.toLowerCase} ${pizzaType.toString} pizza on ${crust.toString}" +
      extraMeat.map(m => s" with ${m.toString}").getOrElse("") +
      extraTopping.map(t => s" with ${t.toString}").getOrElse("")

  val drinkPrice: Double = Lemonade.price
  val basePrice: Double = pizzaType.price * size.factor
  val extraMeatPrice: Double = extraMeat.map(_.price).getOrElse(0.0)
  val extraToppingPrice: Double = extraTopping.map(_.price).getOrElse(0.0)
  val price: Double = basePrice + extraMeatPrice + extraToppingPrice + drinkPrice
}

