object Utils {

  def isSorted(as: List[Int], ordering: (Int, Int) => Boolean): Boolean = {
    as match {
      case Nil => true
      case x :: xs => xs.foldLeft((true, x)) { case ((acc, prev), curr) =>
        (acc && ordering(prev, curr), curr)
      }._1
    }
  }

  def isAscSorted(as: List[Int]): Boolean = {
    isSorted(as, _ <= _)
  }

  def isDescSorted(as: List[Int]): Boolean = {
    isSorted(as, _ >= _)
  }

  def foldLeft[A, B](l: List[A], z: B)(f: (B, A) => B): B =
    l match {
      case Nil => z
      case x :: xs => foldLeft(xs, f(z, x))(f)
    }

  def sum(l: List[Int]): Int = {
    foldLeft(l, 0)(_ + _)
  }

  def length[A](l: List[A]): Int = {
    foldLeft(l, 0)((acc, _) => acc + 1)
  }

  def compose[A, B, C](f: B => C, g: A => B): A => C = {
    x => f(g(x))
  }

  def repeated[A](f: A => A, n: Int): A => A = {
    //
    if (n ==0 ) f
    else compose(f, repeated(f, n - 1))
  }

    def curry[A, B, C](f: (A, B) => C): A => B => C = {
      x => y => f(x, y)
    }

  def uncurry[A, B, C](f: A => B => C): (A, B) => C = {
    (x, y) => f(x)(y)
  }
}

def unSafe[T](ex: Exception)(block: => T): T = {
  try {
    block
  } catch {
    case e: Exception =>
      println(s"Caught exception: $e")
      throw ex
  }
}

def divide(x: Int, y: Int): Int = {
  unSafe(new ArithmeticException("Division by zero")) {
    x / y
  }
}

