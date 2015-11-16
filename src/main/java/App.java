package com.ongroa.knight;

/**
 * Hello world!
 *
 */
public class App {

	int[] new_table =	{
			0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
			0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
			0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
			0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
			0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
			0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
			0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
			0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
			0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
			0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
			0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
			0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	};
	
	int[] table;

	App() {
		table = new int[120];
		init();
	}

	private void init() {
		for (int i = 0; i < 120; i++) {
			table[i] = new_table[i];
		}
	}

	public String getCoordinate(int pos) {
		if (pos < 0 || pos > 119) {
			return "";
		}
		if (table[pos] == 0xff) {
			return "";
		}
		return "" + (char)('a' + (pos - 1) % 10) + (pos / 10 - 1);
	}
	
	public int getPosition(String coord) {
		if (coord == null) {
			return 0;
		}
		if (coord.length() != 2) {
			return 0;
		}
		if (coord.charAt(1) < '1' || coord.charAt(1) > '9') {
			return 0;
		}
		return 10 * (coord.toLowerCase().charAt(0) - 'a' + 2) +
				Integer.parseInt(coord.substring(1, 2));
	}

	public static void main( String[] args ) {
		System.out.println( "Hello World!" );
		new App();
	}
}