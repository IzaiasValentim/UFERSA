package POO.UND1.LISTA.Q12;

public class Main {
	public static void main(String[] args) {
		// Criação de uma instância da classe genérica com atributos do tipo String:
		VerificacaoGenerica<String> stringsGenericas = new VerificacaoGenerica<String>("izaias", "izaias", "isaias");
		// Demonstrações:
		stringsGenericas.verificaIgualdade();
		System.out.println(stringsGenericas);

		// Criação de uma instância da classe genérica com atributos do tipo Double:
		VerificacaoGenerica<Double> reaisGenericos = new VerificacaoGenerica<Double>(4.1D, 4.2D, 4D);
		// Demonstrações:
		reaisGenericos.verificaIgualdade();
		System.out.println(reaisGenericos);

	}
}
