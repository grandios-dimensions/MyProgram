// 「アルゴリズムとデータ構造」二分探索
// Hirohito Shibata (hshibata@edu.teu.ac.jp)
public class BinarySearchA {
    // 最初に呼ばれる関数
    public static void main(String[] args) {
        int n = 100;		// 配列のサイズ
        int[] D = new int[n];	// 配列の生成
        // 配列の初期化 (値を格納)
        for (int i = 0; i < n; i++)
            D[i] = 2 * i;

        // 探索
        int x, r;
        r = binarySearch(D, n, 99);
        System.out.println("binarySearch(99) = " + r);
        r = binarySearch(D, n, 100);
        System.out.println("binarySearch(100) = " + r);
        r = binarySearch(D, n, 101);
        System.out.println("binarySearch(101) = " + r);
        r = binarySearch(D, n, 102);
        System.out.println("binarySearch(102) = " + r);
    }

    // サイズ n の配列 D において値 x を「二分探索」で探す。
    // 見つかったらそのインデックスを返す。なかったら -1 を返す。
    public static int binarySearch(int[] D, int n, int x)
    {
        int left = 0;       // 探索範囲の左
        int right = n - 1;  // 探索範囲の右
        int mid = (left + right) / 2;   // 探索範囲の中央

        while (left < right) {
            if (D[mid] == x)
                return mid;     // Found!
            else if (D[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;

            mid = (left + right) / 2;   // 探索範囲の中央
        }

        if (D[mid] == x)
            return mid;     // Found!
        else
            return -1;      // Not found
    }
}
