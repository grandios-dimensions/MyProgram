
import static HashSearchA.hashInsert;
import static HashSearchA.hashSearch;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Hirohito Shibata
 */
public class HashSearch {
    // ハッシュ法での配列サイズ
    public static int M;
    // ハッシュ法でデータを格納する配列
    public static int[] H;
    
    // 最初に呼ばれる関数
    public static void main(String[] args) {
        // [parameter] 探索対象のデータ
        int[] D = { 5, 6, 9, 10, 15 };  // 挿入するデータ集合
        int n = 5;                      // 挿入するデータ数
            
        // ハッシュの配列を初期化
        M = 2 * n;          // ハッシュのサイズ
        H = new int[M];	// ハッシュの生成
        
        // -1 で初期化
        for (int i = 0; i < M; i++)
            H[i] = -1;
        // 値を挿入
        for (int i = 0; i < n; i++)
            hashInsert(D[i]);
        
        for (int i = 0; i < 20; i++) {
            int result = hashSearch(i);
            System.out.println("hashSearch(" + i + ") = " + result);
        }
    }
    
    // ハッシュ関数
    // 値 x のハッシュ値 (最初の格納場所) を返す
    public static int hash(int x) {
        // 配列サイズは M
        return x % M;
    }

    // サイズ M の配列 H に対して、値 x を格納する。
    public static void hashInsert(int x) {
        // !!#
        // サイズ m の配列 H に対して、値 x を格納する関数を作成せよ。
    }

    // サイズ M の配列 H に対して、値 x が格納されているかを探す。
    // あった場合はその値、なかった場合は負を返す。
    public static int hashSearch(int x) {
        // !!#
        // サイズ M の配列 H に対して、値 x が格納されているかを探す関数を作成せよ。
        // あった場合にはその値、なかった場合には -1 を返すようにせよ。
    }
}
