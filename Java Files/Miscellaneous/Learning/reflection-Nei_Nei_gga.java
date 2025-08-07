import java.lang.reflect.Field;

class reflected {
    public int a = 2;
    public int b = 5;  // completed the incomplete field declaration
}

public class reflection {
    public static void main(String[] args) throws Exception {
        Class ref = reflected.class;
        Field[] fields = ref.getDeclaredFields();
        for (Field field : fields) {
            System.out.println("Field Name  : " + field.getName());
            System.out.println("Field type  : " + field.getType().getName());
        }
    }
}
