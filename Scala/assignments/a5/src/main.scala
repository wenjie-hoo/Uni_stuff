object Main extends App {
  val text = "AB  C D"

  val actionAOutput = Actions.actionA.plugin(text)
  println(s"Action A output: $actionAOutput")

  val actionBOutput = Actions.actionB.plugin(text)
  println(s"Action B output: $actionBOutput")

  val actionCOutput = Actions.actionC.plugin(text)
  println(s"Action C output: $actionCOutput")

  val actionDOutput = Actions.actionD.plugin(text)
  println(s"Action D output: $actionDOutput")

  val actionEOutput = Actions.actionE.plugin(text)
  println(s"Action E output: $actionEOutput")

  val actionFOutput = Actions.actionF.plugin(text)
  println(s"Action F output: $actionFOutput")

  val actionGOutput = Actions.actionG.plugin(text)
  println(s"Action G output: $actionGOutput")
}
