public class VulnApp extends Activity
{
    @Override
    public void onCreate(Bundle savedInstanceState) {
        File file = new File("/data/local/tmp","input");
        String line = "";
        try {
            BufferedReader br =
                new BufferedReader(new FileReader(file));
            line = br.readLine();
        }
        catch (IOException e) {
        }
        main(line);
        finish();
    }
    public static native int main(String content);
}
