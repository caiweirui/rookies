import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

class Page {

    private boolean isEmpty;
    private int id;
    private String idx;
    private int next = Integer.MAX_VALUE;

    public Page(boolean isEmpty, int id, String idx) {
        this.isEmpty = isEmpty;
        this.id = id;
        this.idx = idx;
    }

    public int getNext() {
        return next;
    }

    public void setNext(int next) {
        this.next = next;
    }

    public boolean isEmpty() {
        return isEmpty;
    }

    public void setEmpty(boolean empty) {
        isEmpty = empty;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getIdx() {
        return idx;
    }

    public void setIdx(String idx) {
        this.idx = idx;
    }

    @Override
    public String toString() {
        if (isEmpty) {
            return "-";
        }
        return idx;
    }
}
class Memory {

    private List<Page> memory = new LinkedList<>();
    private int block;
    private int count;
    private int lruFirst;
    private int id = 0;

    Memory(int block) {
        this.block = block;
        for (int i = 0 ;i < block ; i++){
            this.memory.add(new Page(true,0,"-"));
        }
    }

    public boolean isFull(){
        return this.count == this.block;
    }
    public int getCount() {
        return count;
    }
    public void print(int get){
        String res = this.toString();
        System.out.print(res + String.valueOf(get));
    }
    public boolean contains(String val) {
        for (Page p : memory) {
            if (p.getIdx().equals(val)) {
                return true;
            }
        }
        return false;
    }
    public void add(String val) {
        count += 1;
        for (Page s : memory) {
            if (s.isEmpty()){
                s.setIdx(val);
                s.setId(id++);
                s.setEmpty(false);
                break;
            }
        }
    }

    public void fifo(String val) {
        Page first = memory.get(0);
        int min = Integer.MAX_VALUE;
        for (Page p : memory) {
            if (p.getId() < min) {
                min = p.getId();
                first = p;
            }
        }
        first.setId(id++);
        first.setIdx(val);
        first.setEmpty(false);
    }

    public void opt(String val) {
        Page first = memory.get(0);
        int max = Integer.MIN_VALUE;
        
        boolean wq = false;
        for (Page p : memory) {
            if (p.getNext() > max) {
                max = p.getNext();
                first = p;
                if (p.getNext() == Integer.MAX_VALUE){
                    wq= true;
                    break;
                }
            }
        }
        if (wq) {
            int mid = Integer.MAX_VALUE;
            for (Page p : memory) {
                if (p.getNext()==Integer.MAX_VALUE) {
                    if (p.getId() < mid) {
                        mid = p.getId();
                        first = p;
                    }
                }
            }
        }
        
        first.setId(id++);
        first.setIdx(val);
        first.setEmpty(false);
    }

    public void searchNxt(List<String> pages,int start) {
        for (Page p : memory){
            p.setNext(Integer.MAX_VALUE);
        }
        for (Page p : memory) {
            for (int i = start + 1; i < pages.size(); i++) {
                if (pages.get(i).equals(p.getIdx())) {
                    p.setNext(i);
                    break;
                }
            }
        }
    }

    public void lru(String val) {
        memory.remove(0);
        memory.add(new Page(false,id++,val));
    }

    public void toLast(String val) {
        for (Page page: memory) {
            if (page.getIdx().equals(val)) {
                memory.remove(page);
                memory.add(count-1,page);
                break;
            }
        }
    }


    @Override
    public String toString() {
        StringBuffer res = new StringBuffer();
        for (Page ech : memory) {
            res.append(ech.toString() + ",");
        }
        return res.toString();
    }
}

public class Main {

    private static int method;

    private static int block;

    private static int miss = 0;

    private static List<String> pages;

    private static Memory memory ;

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        method = scanner.nextInt();
        block = scanner.nextInt();

        memory = new Memory(block);
        scanner.nextLine();

        pages = Arrays.asList(scanner.nextLine().split(","));

        switch (method) {
            case 1:
                opt();
                break;
            case 2:
                fifo();
                break;
            case 3:
                lru();
                break;
        }


    }

    private static void fifo(){

        for (int i = 0 ; i < pages.size() ; i++) {
            String val = pages.get(i);
            if (memory.contains(val)){
                memory.print(1);
            }else if (!memory.isFull()){
                miss += 1;
                memory.add(val);
                memory.print(0);
            } else {
                memory.fifo(val);
                memory.print(0);
                miss += 1;
            }
            if (i == pages.size() -1) {
                System.out.println();
            }else {
                System.out.print("/");
            }

        }
        System.out.println(miss);
    }

    private static void opt(){
        for (int i = 0 ; i < pages.size() ; i++) {
            String val = pages.get(i);
            if (memory.contains(val)){
                memory.print(1);
            }else if (!memory.isFull()){
                miss += 1;
                memory.add(val);
                memory.print(0);
            }else {
                memory.searchNxt(pages,i);
                memory.opt(val);
                memory.print(0);
                miss += 1;
            }
            if (i == pages.size() -1) {
                System.out.println();
            }else {
                System.out.print("/");
            }
        }

        System.out.println(miss);

    }

    private static void lru(){
        for (int i = 0 ; i < pages.size() ; i++) {
            String val = pages.get(i);
            if (memory.contains(val)){
                memory.toLast(val);
                memory.print(1);
            }else if (!memory.isFull()){
                memory.add(val);
                memory.print(0);
                miss += 1;
            } else {
                memory.lru(val);
                memory.print(0);
                miss += 1;
            }
            if (i == pages.size() -1) {
                System.out.println();
            }else {
                System.out.print("/");
            }
        }
        System.out.println(miss);
    }

}