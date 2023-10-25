import Utils._
object Main {
  def main(args: Array[String]): Unit = {
    testCompose()
    testRepeated()
    testCurry()
    testUncurry()
  }

  def testCompose(): Unit = {
    val f: Int => Int = x => x * 2
    val g: Int => String = x => s"The result is $x"
    val h = Utils.compose(g, f)
    assert(h(10) == "The result is 20", s"Test failed: ${h(10)}")
    println("Compose test passed")
  }

  def testRepeated(): Unit = {
    val addOne: Int => Int = x => x + 1
    val addTwo = Utils.repeated(addOne, 2)
    assert(addTwo(10) == 12, s"Test failed: ${addTwo(10)}")
    println("Repeated test passed")
  }

  def testCurry(): Unit = {
    def add(a: Int, b: Int): Int = a + b
    val addCurried: Int => Int => Int = Utils.curry(add)
    assert(addCurried(1)(2) == 3, s"Test failed: ${addCurried(1)(2)}")
    println("Curry test passed")
  }

  def testUncurry(): Unit = {
    def multiply(a: Int)(b: Int): Int = a * b
    val multiplyUncurried: (Int, Int) => Int = Utils.uncurry(multiply)
    assert(multiplyUncurried(2, 3) == 6, s"Test failed: ${multiplyUncurried(2, 3)}")
    println("Uncurry test passed")
  }
}
