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
   (for (i <- 0 until xs.length) yield xs(i) * ys(i)).sum s
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
    sort(left) ::: equal ::: sort(right)
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
  def isPrime(n: Int): Boolean = {
    if (n <= 1) false
    else if (n == 2) true
    else 
      !(2 until n).exists(i => n % i == 0)
  }
  var i = 2
  var pairs = List[(Int, Int)]()

  while (i < n) {
    var j = 1
    while (j < i) {
      if (isPrime(i + j)) {
        pairs = (j, i) :: pairs
      }
      j += 1
    }
    i += 1
  }
  pairs
}


def primePairs(n: Int): List[(Int, Int)] = {

  def isPrime(n: Int): Boolean = {
    if (n <= 1) false
    else if (n == 2) true
    else 
      !(2 until n).exists(i => n % i == 0)
  }
  val pairs = for {
    i <- 2 until n
    j <- 1 until i
    if isPrime(i + j)
  } yield (j, i)
  pairs.toList
}


import java.io.{BufferedReader, FileReader}
import java.io.File
import scala.io.Source

val file = new File("/Users/clarkhu/Desktop/SIP/assignments/a1/a1.txt")
def fileLinesUgly(file: java.io.File): List[String] = {
  val reader = new BufferedReader(new FileReader(file))
  var lines = List[String]()
  try {
    var line = reader.readLine()
    while (line != null) {
      lines = line :: lines
      line = reader.readLine()
    }
  } finally {
    reader.close()
  }
  lines.reverse
}



val file = new File("/Users/clarkhu/Desktop/SIP/assignments/a1/a1.txt")
def fileLines(file: java.io.File): List[String] = {
  val bufferedSource = Source.fromFile(file)
  val lines = bufferedSource.getLines().toList
  bufferedSource.close()
  lines
}



def printNonEmptyUgly(pattern: String): Unit = {
  val filesHere = new File("/Users/clarkhu/Desktop/SIP/assignments/a1/").listFiles()
  var i = 0
  while (i < filesHere.length) {
    val file = filesHere(i)
    if (file.getName.endsWith(pattern) && file.length() > 0) {
      println(file.getName)
    }
    i += 1
  }
}


def printNonEmpty(pattern: String): Unit = {
  val filesHere = new File("/Users/clarkhu/Desktop/SIP/assignments/a1/").listFiles()
  for (file <- filesHere if file.getName.endsWith(pattern)
    if file.isFile
    if file.length()>0){
  println(file.getName)}
}

