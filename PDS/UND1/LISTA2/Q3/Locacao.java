
import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.Date;

/**
 * 
 * A classe Locacao armazena dados a respeito da locação de um filme específico.
 * - O filme é inserido na classe atravez da composição.
 * - A data de locação e devolução são automaticamente definidos de acordo com o
 * dia atual e o prazo padrão de locação.;
 * - O prazo de locação também pode ser extendido.
 * - É possível finalizar a Locação. Depois de finalizada o campo estaFinalizada
 * fica 'verdadeiro'
 */
public class Locacao {

	public static final int diasDeLocacao = 7;
	public static final int acrescimo = 3;

	Filme filmeLocacao;
	Date dataLocacao;
	Date dataDevolução;
	boolean estaFinalizada;

	public Locacao(Filme filmeLocacao) {
		this.filmeLocacao = filmeLocacao;
		this.dataLocacao = Date.from(Instant.now());
		this.dataDevolução = Date.from(dataLocacao.toInstant().plus(diasDeLocacao, ChronoUnit.DAYS));
		this.estaFinalizada = false;
	}

	public static int getDiasdelocacao() {
		return diasDeLocacao;
	}

	public Filme getFilmeLocacao() {
		return filmeLocacao;
	}

	public void setFilmeLocacao(Filme filmeLocacao) {
		this.filmeLocacao = filmeLocacao;
	}

	public Date getDataLocacao() {
		return dataLocacao;
	}

	public void setDataLocacao(Date dataLocacao) {
		this.dataLocacao = dataLocacao;
	}

	public Date getDataDevolução() {
		return dataDevolução;
	}

	// Aumenta o prazo de acordo com os dias solicitados de acrescimo.
	public void setDataDevolução() {
		this.dataDevolução = Date.from(dataDevolução.toInstant().plus(acrescimo, ChronoUnit.DAYS));
	}

	public String isEstaFinalizada() {
		return estaFinalizada == true ? "Finalizada" : "Em andamento";
	}

	public void setEstaFinalizada(boolean estaFinalizada) {
		this.estaFinalizada = (estaFinalizada == false) ? true : estaFinalizada;
	}

}
