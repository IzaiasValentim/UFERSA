package POO.UND2.LISTA.Q31;

public class Main {
	public static void main(String[] args) {
		// Criando e exibindo um prefeito.
		Prefeito prefeito = new Prefeito("Meu prefeito", 55, "Não sei", "Cidade dade");
		System.out.println(prefeito);

		System.out.println(); // Apenas uma quebra de linha.
		
		// Criando e exibindo um governador.
		Governador governador = new Governador("Nosso governador", 65, "Não sei", "Estado tado");
		System.out.println(governador);
	}
}
