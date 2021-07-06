package aaa.com;

//package InputOutputStream;

//import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class TxtRead {
	//csv 파일 읽음!!!
    public static void main(String[] args) throws IOException {
	 try {
	       // 바이트 단위로 파일읽기
	        String filePath = "C:/Users/KOSTA/eclipse-workspace/aaa/src/main/webapp/CRUDmovie.csv";
	        		//"D:/Eclipse/Java/Output.txt"; // 대상 파일
	       // "C:/Users/KOSTA/Desktop/CRUDmovie.txt";
	        FileInputStream fileStream = null; // 파일 스트림
	        
	        fileStream = new FileInputStream( filePath );// 파일 스트림 생성
	        //버퍼 선언
	        byte[ ] readBuffer = new byte[fileStream.available()];
	        while (fileStream.read( readBuffer ) != -1){}
	        System.out.println(new String(readBuffer)); //출력

	        fileStream.close(); //스트림 닫기
	    } catch (Exception e) {
		e.getStackTrace();
	    }
    }
	
}
