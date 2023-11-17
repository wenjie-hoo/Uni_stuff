import plugins._

object Actions {
  val actionA: Pluginable = new Pluginable with Shortening with Doubling with SingleSpacing
  val actionB: Pluginable = new Pluginable with Doubling with Shortening with NoSpacing
  val actionC: Pluginable = new Pluginable with Doubling with LowerCasing
  val actionD: Pluginable = new Pluginable with Rotating with DuplicateRemoval
  val actionE: Pluginable = new Pluginable with Reverting with Doubling with Shortening with NoSpacing
  val actionF: Pluginable = List.fill(5)(new Rotating {}).foldLeft(new Pluginable {}) {
    (acc, p) => new Pluginable {
      override def plugin(text: String): String = p.plugin(acc.plugin(text))
    }
  }
  val actionG: Pluginable = new Pluginable  {
    override def plugin(text: String): String = actionB.plugin(actionA.plugin(text))
  }
}