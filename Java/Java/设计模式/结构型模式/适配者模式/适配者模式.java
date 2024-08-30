package 设计模式.结构型模式.适配者模式;

/**
 * @author robbie
 * @date Created in 2024/08/13
 */

interface MediaPlayer {
    void play(String mediaType);
}

interface AnotherMediaPlayer {
    void playVLC();

    void playMP4();
}

class VLC implements AnotherMediaPlayer {
    @Override
    public void playVLC() {
        System.out.println("Playing VLC.");
    }

    @Override
    public void playMP4() {
        // do nothing
    }
}

class MP4 implements AnotherMediaPlayer {
    @Override
    public void playVLC() {
        // do nothing
    }

    @Override
    public void playMP4() {
        System.out.println("Playing MP4.");
    }
}

class Adapter implements MediaPlayer {
    private AnotherMediaPlayer anotherMediaPlayer;

    public Adapter(String mediaType) {
        if ("vlc".equalsIgnoreCase(mediaType)) {
            anotherMediaPlayer = new VLC();
        } else if ("mp4".equalsIgnoreCase(mediaType)) {
            anotherMediaPlayer = new MP4();
        }
    }

    @Override
    public void play(String mediaType) {
        if ("vlc".equalsIgnoreCase(mediaType)) {
            anotherMediaPlayer.playVLC();
        } else if ("mp4".equalsIgnoreCase(mediaType)) {
            anotherMediaPlayer.playMP4();
        }
    }
}

class AudioPlayer implements MediaPlayer {

    @Override
    public void play(String mediaType) {
        if("mp3".equalsIgnoreCase(mediaType)){
            playMP3();
        } else if ("vlc".equalsIgnoreCase(mediaType) || "mp4".equalsIgnoreCase(mediaType)) {
            new Adapter(mediaType).play(mediaType);
        }else {
            System.out.println(String.format("media type '%s' not supported", mediaType));
        }
//        playMP3();
    }

    public void playMP3(){
        System.out.println("Playing MP3.");
    }
}

public class 适配者模式 {
    public static void main(String[] args) {
        new AudioPlayer().play("vlc");
        new AudioPlayer().play("mp4");
        new AudioPlayer().play("mp3");

        new AudioPlayer().play("avi");
    }
}
