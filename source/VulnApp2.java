package sqlab.craxdroid.vulnapp2;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;

public class VulnApp extends Activity
{
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        File file = new File("/data/local/tmp","input");
        String line = "";

        try {
            BufferedReader br = new BufferedReader(new FileReader(file));

            line = br.readLine();
        }
        catch (IOException e) {
        }

        main(line);
        finish();
    }

    static {
        System.loadLibrary("VulnApp2");
    }

    public static native int main(String content);
}

