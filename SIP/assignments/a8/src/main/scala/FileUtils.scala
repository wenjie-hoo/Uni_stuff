import java.io.{File, FileWriter}
import scala.util.Using

object FileUtils {
  def writeToFile(filename: String, lines: Seq[String]): Unit = {
    val file = new File(filename)
    Using(new FileWriter(file, true)) { writer =>
      lines.foreach(line => writer.write(line + "\n"))
    }
  }
}
