package plugins

trait Pluginable {def plugin(text: String): String = text}

trait Reverting extends Pluginable {override def plugin(text: String): String = super.plugin(text.reverse)}

trait LowerCasing extends Pluginable{override def plugin(text: String): String = super.plugin(text.toLowerCase)}

trait SingleSpacing extends Pluginable {override def plugin(text: String): String = super.plugin(text.replaceAll("\\s+", " "))}

trait NoSpacing extends Pluginable {override def plugin(text: String): String = super.plugin(text.replaceAll("\\s", ""))}

trait DuplicateRemoval extends Pluginable {override def plugin(text: String): String = super.plugin(text.filterNot(c => text.count(_ == c) > 1))}

trait Rotating extends Pluginable {override def plugin(text: String): String = super.plugin(text.tail + text.head)}

trait Doubling extends Pluginable{
  override def plugin(text: String): String = super.plugin(text.zipWithIndex.map {
    case (s, i) if i % 2 == 0 => s"$s$s"
    case (c, _) => c.toString
  }.mkString(""))}

trait Shortening extends Pluginable{
  override def plugin(text: String): String = super.plugin(text.zipWithIndex.filterNot {
    case (_, i) => i % 2 != 0
  }.map(_._1).mkString(""))
}



