import com.restfb.types.User
import com.restfb.{DefaultFacebookClient, Version}
import scala.concurrent.ExecutionContext.Implicits.global
import scala.concurrent.Future

object FacebookAdapter {
  private val myAppSecret = "00446b2d0f52f1448a90c89515b38c31"
  private class MyFacebookClient(currentAccessToken: String)
    extends DefaultFacebookClient(
      currentAccessToken,
      myAppSecret,
      Version.VERSION_6_0) {}

  def getUser(accessToken: String, id: String): Future[User] = Future {
    val client = new MyFacebookClient(accessToken)
    val user = client.fetchObject(id, classOf[User])
    user
  }
}