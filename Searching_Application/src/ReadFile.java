import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;

import com.csvreader.CsvReader;

public class ReadFile {
	
	private String path;
	
	public ReadFile(String path) {
		// TODO Auto-generated constructor stub
		this.path=path;
	}
	/**
	 * read data from filename
	 * @param filename
	 * @param header header of table
	 * @return
	 */
	ArrayList<String[]> readData(String filename,boolean header){
		ArrayList<String[]> datas=new ArrayList<>();
		try {
			CsvReader csvReader=new CsvReader(path+"/"+filename);
			if (header) {
				csvReader.readHeaders();
			}
			while (csvReader.readRecord()) {
				String []cols=new String[csvReader.getColumnCount()];
				for (int i = 0; i < cols.length; i++) {
					cols[i]=csvReader.get(i).trim();
				}
				datas.add(cols);
			}
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		return datas;
	}

}
