package POO.UND1.LISTA.Q12;

public class VerificacaoGenerica<T> {
	private T atributo1;
	private T atributo2;
	private T atributo3;

	public VerificacaoGenerica(T at1, T at2, T at3) {
		atributo1 = at1;
		atributo2 = at2;
		atributo3 = at3;
	}

	public void verificaIgualdade() {
		int cont = 0;

		if (atributo1.equals(atributo2)) {
			cont += 2;
			if (atributo1.equals(atributo3)) {
				cont++;
			}
		} else if (atributo1.equals(atributo3)) {
			cont += 2;
		} else if (atributo2.equals(atributo3)) {
			cont += 2;
		} else {
			cont += 0;
		}

		System.out.println("\nNúmero de atributos iguais: " + cont);
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("VerificacaoGenerica{");
		sb.append("atributo1=").append(atributo1);
		sb.append(", atributo2=").append(atributo2);
		sb.append(", atributo3=").append(atributo3);
		sb.append('}');
		return sb.toString();
	}

}
