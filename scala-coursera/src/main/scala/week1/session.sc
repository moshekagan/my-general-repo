object Session {
  1 + 2

  def abs(x: Double) = if (x < 0) -x else x

  def isGoodEnough(guess: Double, x: Double) = {
//    println(abs(guess * guess - x) / x + "\n")
    abs(guess * guess - x) / x < 0.001
  }

  def improve(guess: Double, x: Double) = {
//    println(s"guess = $guess\nx= $x\n" + (guess + x / guess) / 2)
    (guess + x / guess) / 2
  }

  def sqrtIter(guess: Double, x: Double): Double =
    if (isGoodEnough(guess, x)) guess
    else sqrtIter(improve(guess, x), x)

  def sqrt(x: Double) = sqrtIter(1.0, x)

  sqrt(2)
  sqrt(4)
  sqrt(1e-6)
//  sqrt(1e60)
`
//  sqrt(0.001)
//  sqrt(0.1e-20)
//  sqrt(0.1e20)
//  sqrt(0.0e50)
}