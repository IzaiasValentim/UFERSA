package POO.UND2.LISTA.Q28;

public class TestaEquipamento {
	public static void main(String[] args) {
		// Instanciando e mostrando um equipamento
		Equipamento telemovel = new Equipamento("Smartphone", "Isumg");
		System.out.println(telemovel);
		
		System.out.println();

		// Instanciando e mostrando um computador
		Computador g15 = new Computador("Computador", "Dell", "G15", 4000F);
		System.out.println(g15);
	}
}
