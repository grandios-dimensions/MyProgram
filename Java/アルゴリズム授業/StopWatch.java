// ストップウォッチ
public class StopWatch {
    private long start = 0;     // スタート時間
    private long stop = 0;      // 終了時間
    private long elapsed = 0;   // 経過時間

    // ストップウォッチの開始
    public void start()
    {
        java.util.Date watch = new java.util.Date();
        start = watch.getTime();
    }

    // ストップウォッチの終了
    public void stop()
    {
        java.util.Date watch = new java.util.Date();
        stop = watch.getTime();
        elapsed = stop - start;
    }

    // ミリ秒の時間を取得
    public long getMillisec()
    {
        return elapsed;
    }

    // 経過時間をプリント
    public void printTime()
    {
        System.out.println("*** Elapsed = " + elapsed + " (Start = " + start + " , Stop = " + stop);
    }
}