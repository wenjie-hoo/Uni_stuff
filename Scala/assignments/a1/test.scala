def scalarUgly(xs: List[Int], ys: List[Int]): Int = {
  var i = 0
  var scalar = 0
  while (i < xs.length) {
    scalar += xs(i) * ys(i)
    i += 1
  }
  scalar
}

def scalar(xs: List[Int], ys: List[Int]) = {
  val scalar = (for (i <- 0 until xs.length) yield xs(i) * ys(i)).sum
  scalar
}

def sortUgly(xs: List[Int]): List[Int] = {
  if (xs.length <= 1)
    xs
  else {
    val pivot = xs(xs.length / 2)
    var left, right, equal = List[Int]()
    var i = 0
    while (i < xs.length) {
      if (xs(i) < pivot) left = xs(i) :: left
      else if (xs(i) > pivot) right = xs(i) :: right
      else equal = xs(i) :: equal
      i += 1
    }
    sortUgly(left) ::: equal ::: sortUgly(right)
  }   
}

def sort(xs: List[Int]): List[Int] = {
  if (xs.length <= 1) xs
  else {
    val pivot = xs(xs.length / 2)
    val left = for (x <- xs if x < pivot) yield x
    val right = for (x <- xs if x > pivot) yield x
    val equal = for (x <- xs if x == pivot) yield x

    sort(left) ::: equal ::: sortUgly(right)
  }
}

def isPrimeUgly(n: Int): Boolean = {
  if (n <= 1) false
  else {
    var i = 2
    var prime = true
    while (i * i <= n && prime) {
      if (n % i == 0) prime = false
      i += 1
    }
    prime
  }
}

def isPrime(n: Int): Boolean = {
  if (n <= 1) false
  else if (n == 2) true
  else 
    !(2 until n).exists(i => n % i == 0)
}


def primePairsUgly(n: Int): List[(Int, Int)] = {
  val pairs = scala.collection.mutable.ListBuffer[(Int, Int)]()
  var i = 2
  while (i < n) {
    var j = 1
    while (j < i) {
      if (isPrime(i + j)) {
        pairs += ((i, j))
      }
      j += 1
    }
    i += 1
  }
  pairs.toList
}






