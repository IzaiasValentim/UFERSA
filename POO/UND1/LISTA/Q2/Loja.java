
public class Loja {
	public static void main(String args[]) {
		// Instânciamento de uma fatura e definição de seus atributos.
		Fatura fatura = new Fatura();
		fatura.setNumeroDeIdentificacao(1);
		fatura.setDescricao("Cadeira");
		fatura.setQuantidadeComprada(5);
		fatura.setPrecoPorItem(100.0);

		// Demonstrações das saídas esperadas:
		System.out.println("O total da fatura é: " + fatura.calcularTotal());

		fatura.setQuantidadeComprada(-1);
		fatura.setPrecoPorItem(-1.0);

		System.out.println("O total da fatura é: " + fatura.calcularTotal());
	}
}
