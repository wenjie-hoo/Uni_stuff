import Utils._

val list1 = List(1, 2, 3, 4, 5)
val list2 = List(5, 4, 3, 2, 1)

println(isAscSorted(list1))
println(isAscSorted(list2))
println(isDescSorted(list1))
println(isDescSorted(list2))
println(isSorted(list1, (x, y) => x >= y))
println(foldLeft(List(1, 2, 3, 4, 5), 0)(_ + _))
println(sum(List(1, 2, 3, 4, 5)))
println(length(list1))

val f: Int => Int = x => x * 2
val g: Int => String = x => s"The result is $x"
val h = compose(g, f)
println(h(10))

val addOne: Int => Int = x => x + 1
val addTwo = Utils.repeated(addOne, 2)
println(addTwo(10)) // prints 12


def add(a: Int, b: Int): Int = a + b
val addCurried: Int => Int => Int = Utils.curry(add)
println(addCurried(1)(2)) // prints 3

def multiply(a: Int)(b: Int): Int = a * b
val multiplyUncurried: (Int, Int) => Int = Utils.uncurry(multiply)
println(multiplyUncurried(2, 3)) // prints 6
