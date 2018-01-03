import java.io.*;

class ovation {
	public static void main(String[] args) {
		try{
			InputStreamReader ir = new InputStreamReader(new FileInputStream(args[0]));
			BufferedReader br = new BufferedReader(ir);
			FileWriter fw = new FileWriter(args[1]);
			BufferedWriter bw = new BufferedWriter(fw);
			int T = Integer.parseInt(br.readLine());
			String line = "";
			int index = 1;
			while((line = br.readLine()) != null) {
				String[] contents = line.split(" ");
				int maxIndex = Integer.parseInt(contents[0]);
				int pplStanding = 0;
				int pplAdding = 0;
				
				for(int i = 0; i <= maxIndex; i++) {
					int pplAtI = Integer.parseInt(contents[1].substring(i, i + 1));
					if(i > pplStanding) {
						pplAdding += i - pplStanding;
						pplStanding = i;
					}
					pplStanding += pplAtI;
				}
				bw.write("Case #" + index+": " + pplAdding);
				bw.newLine();
				index++;
			}
			br.close();
			bw.close();
		}
		catch(Exception e) {
			System.out.println("exception!");
		}

	}
}