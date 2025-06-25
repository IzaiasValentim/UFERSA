package Q7;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

// Target (Interface desejada pelo novo sistema)
interface ServicoDeDadosEscolar {
    List<Aluno> obterListaDeAlunos();
}

// Classe de Modelo de Dados para o novo sistema
class Aluno {
    private String nome;
    private int matricula;

    public Aluno(String nome, int matricula) {
        this.nome = nome;
        this.matricula = matricula;
    }

    public String getNome() {
        return nome;
    }

    public int getMatricula() {
        return matricula;
    }

    @Override
    public String toString() {
        return "Aluno [Nome: " + nome + ", Matr�cula: " + matricula + "]";
    }
}

// Adaptee (Biblioteca Legada com interface incompat�vel)
class BibliotecaLegadaAlunos {
    // Simula dados em um formato antigo (ex: Map onde a chave � um ID de string e o valor � o nome completo)
    public Map<String, String> carregarAlunosAntigoFormato() {
        System.out.println("Biblioteca Legada: Carregando alunos no formato antigo...");
        Map<String, String> dadosAntigos = new HashMap<>();
        dadosAntigos.put("ID001", "Jo�o Silva");
        dadosAntigos.put("ID002", "Maria Oliveira");
        dadosAntigos.put("ID003", "Pedro Souza");
        return dadosAntigos;
    }
}

// Adapter (por Composi��o)
class AdaptadorBibliotecaAlunos implements ServicoDeDadosEscolar {
    private BibliotecaLegadaAlunos bibliotecaLegada;

    public AdaptadorBibliotecaAlunos(BibliotecaLegadaAlunos bibliotecaLegada) {
        this.bibliotecaLegada = bibliotecaLegada;
    }

    @Override
    public List<Aluno> obterListaDeAlunos() {
        System.out.println("Adaptador: Adaptando dados da biblioteca legada...");
        Map<String, String> dadosAntigos = bibliotecaLegada.carregarAlunosAntigoFormato();
        List<Aluno> alunosConvertidos = new ArrayList<>();

        // L�gica de convers�o do formato antigo para o novo formato de Aluno
        int matriculaBase = 1000; // Simula a gera��o de matr�cula
        for (Map.Entry<String, String> entrada : dadosAntigos.entrySet()) {
            String idAntigo = entrada.getKey(); // Pode ser usado como parte da matr�cula ou ignorado
            String nomeCompleto = entrada.getValue();
            // A l�gica aqui pode ser mais complexa dependendo do mapeamento real
            alunosConvertidos.add(new Aluno(nomeCompleto, matriculaBase++));
        }
        System.out.println("Adaptador: Dados adaptados com sucesso.");
        return alunosConvertidos;
    }
}

// Cliente (Novo Sistema de Gest�o Escolar)
class NovoSistemaGestaoEscolar {
    private ServicoDeDadosEscolar servicoDeDados;

    public NovoSistemaGestaoEscolar(ServicoDeDadosEscolar servicoDeDados) {
        this.servicoDeDados = servicoDeDados;
    }

    public void exibirAlunos() {
        System.out.println("\n--- Novo Sistema de Gest�o Escolar: Exibindo Alunos ---");
        List<Aluno> alunos = servicoDeDados.obterListaDeAlunos();
        for (Aluno aluno : alunos) {
            System.out.println(aluno);
        }
    }

    public static void main(String[] args) {
        // Instancia a biblioteca legada
        BibliotecaLegadaAlunos bibliotecaLegada = new BibliotecaLegadaAlunos();

        // Instancia o adaptador, passando a biblioteca legada para ele
        ServicoDeDadosEscolar adaptador = new AdaptadorBibliotecaAlunos(bibliotecaLegada);

        // O novo sistema usa o adaptador como se fosse o servi�o de dados desejado
        NovoSistemaGestaoEscolar sistema = new NovoSistemaGestaoEscolar(adaptador);
        sistema.exibirAlunos();
    }
}
