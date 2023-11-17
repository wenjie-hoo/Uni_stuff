import money._

val sum1: Money = Money(100)(USD)+Money(100)(PLN)
val sum2: Money = Money(100)(EUR)+ Money(100)(PLN)
val sum3: Money = Money(200)(PLN)+ Money(450)(USD)

val sub1: Money = Money(300)(USD) - Money(100)(EUR)
val sub1: Money = Money(100)(EUR) - Money(100)(PLN)

val mult1: Money = Money(30)(EUR) * 2 + Money(10)(PLN)
val mult1: Money = Money(30)(PLN) * 2 + Money(19)(USD)

val conv1: Money = Money(150)(USD) as PLN
val conv1: Money = Money(100)(PLN) as EUR

val compare1: Boolean = Money(1)(PLN) > Money(200)(EUR)
val compare2: Boolean = Money(300)(PLN) < Money(200)(EUR)
val compare3: Boolean = Money(1)(EUR) < Money(1)(USD)
