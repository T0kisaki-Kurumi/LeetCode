package 设计模式.结构型模式.代理模式;

/**
 * @author robbie
 * @date Created in 2024/08/15
 */

interface Image{
    void display();
}

class SpringImage implements Image{
    @Override
    public void display() {
        System.out.println(
                "  .   ____          _            __ _ _\n" +
                " /\\\\ / ___'_ __ _ _(_)_ __  __ _ \\ \\ \\ \\\n" +
                "( ( )\\___ | '_ | '_| | '_ \\/ _` | \\ \\ \\ \\\n" +
                " \\\\/  ___)| |_)| | | | | || (_| |  ) ) ) )\n" +
                "  '  |____| .__|_| |_|_| |_\\__, | / / / /\n" +
                " =========|_|==============|___/=/_/_/_/");
    }
}

class ProxyImage implements Image{
    private SpringImage springImage;

    @Override
    public void display() {
        if(springImage == null){
            springImage = new SpringImage();
        }
        springImage.display();
    }
}

public class 代理模式 {
    public static void main(String[] args) {
        ProxyImage proxyImage = new ProxyImage();
        proxyImage.display();
    }
}
