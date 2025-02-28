package POO.UND1.LISTA.Q11;

public class Main {
	public static void main(String args[]) {
		RegistroAcademico.infoRegistros();

		RegistroAcademico registrarIzaias = new RegistroAcademico("Luis Izaias", 02, 0.7D);

		registrarIzaias.imprime();
		// O número de matrículas pode ser visualizado diretamente pelo valor.
		System.out.println("Total de matrículas: " + RegistroAcademico.numeroDeMatriculas);

		RegistroAcademico registrarTayanar = new RegistroAcademico("Janyele Taynar", 010, 0.4D);

		registrarTayanar.imprime();
		// Ou acessando o método estático pela Classe.
		RegistroAcademico.infoRegistros();

		RegistroAcademico registrarTonha = new RegistroAcademico("Joana Tonha", 07, 0.6D);

		registrarTonha.imprime();
		RegistroAcademico.infoRegistros();
	}
}
