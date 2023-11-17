import plugins.{Pluginable, Reverting}
import org.scalatest.funsuite.AnyFunSuite

//class ExampleSuite320 extends AnyFunSuite {}
class PluginableSpec extends AnyFunSuite with Reverting {
  "Reverting plugin" should "reverse the input text" in {
    val pluginable = new Object with Pluginable with Reverting
    val result = pluginable.plugin("Hello")
    result should be("olleH")
  }

  // Add the rest of your test cases for other traits here
}
