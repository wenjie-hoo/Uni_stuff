import Utils.{isAscSorted, *}

object Main {
  val list1 = List(1, 2, 3, 4, 5)
  val list2 = List(5, 4, 3, 2, 1)

  def main(args: Array[String]): Unit = {
    testIsSorted()
    testIsAscSorted()
    testIsDescSorted()
    testFoldLeft()
    testSum()
    testLength()
    testCompose()
    testRepeated()
    testCurry()
    testUncurry()
    testDivide()
  }

//  println(isDescSorted(list1)) // false
//  println(isDescSorted(list2)) // true
//  println(isSorted(list1, (x, y) => x >= y))

  def testIsSorted(): Unit = {
    println("test is sorted")
    println(isAscSorted(list1))
    println(isAscSorted(list2))
  }

  def testIsAscSorted(): Unit = {
    println("test is AscSorted")
    println(isAscSorted(list1))
    println(isAscSorted(list2))
  }

  def testIsDescSorted():Unit = {
    println("test is DescSorted")
    println(isDescSorted(list1))
    println(isDescSorted(list2))
  }
  def testFoldLeft():Unit = {
    println("test FoldLeft")
    println(foldLeft(list1, 1)(_ + _))
    //16
  }
  def testSum():Unit = {
    println("test Sum")
    println(sum(list1))
    // 15
  }
  def testLength():Unit = {
    println("test Length")
    println(length(list1))
  }
  def testCompose(): Unit = {
    val f: Int => Int = x => x * 2
    val g: Int => String = x => s"The result is $x"
    val h = Utils.compose(g, f)
    assert(h(10) == "The result is 20", s"Test failed: ${h(10)}")
    println("Compose test passed")
  }

  def testRepeated(): Unit = {
    println("test repeated")
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


def testDivide(): Unit = {
  val result1 = divide(10, 2)
  println(s"Result1: $result1")

  val result2 = divide(10, 0)
  println(s"Result2: $result2")
}
