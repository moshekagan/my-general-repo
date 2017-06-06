package example

/**
  * Created by moshek on 18/09/2016.
  */
object Example extends App {

  println("hello world")

  def sum(f: Int => Int): (Int, Int) => Int = {
    def sumf(a: Int, b: Int): Int = a + b
    sumf
  }

  println(s" 5 + 3 = ${sum(x => x * x * x)(1, 10)}")


  val xs = List(1, 3,4,2,5,7,9,0,2,54,64)

  println( xs partition (_ > 3) )
  println( xs span (_ >= 1) )

  println( xs zipWithIndex )
  println( ( (xs zip (Stream from 3)) unzip) _1 )
  val (first, second) = (xs zip (Stream from 3)) unzip

  println(s"FIRST = $first")

  val groupByExample = xs groupBy (x => {
    if (x % 2 == 0)       "EVEN"
    else if (x % 3 == 0)  "THREE"
    else                  "NONE"
  })
  println( groupByExample )
  println( groupByExample get "THREE" )

  println( (1 to 1000) toStream)


}

