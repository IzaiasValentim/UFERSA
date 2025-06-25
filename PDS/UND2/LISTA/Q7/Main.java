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
        return "Aluno [Nome: " + nome + ", Matrícula: " + matricula + "]";
    }
}

// Adaptee (Biblioteca Legada com interface incompatível)
class BibliotecaLegadaAlunos {
    // Simula dados em um formato antigo (ex: Map onde a chave é um ID de string e o valor é o nome completo)
    public Map<String, String> carregarAlunosAntigoFormato() {
        System.out.println("Biblioteca Legada: Carregando alunos no formato antigo...");
        Map<String, String> dadosAntigos = new HashMap<>();
        dadosAntigos.put("ID001", "João Silva");
        dadosAntigos.put("ID002", "Maria Oliveira");
        dadosAntigos.put("ID003", "Pedro Souza");
        return dadosAntigos;
    }
}

// Adapter (por Composição)
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

        // Lógica de conversão do formato antigo para o novo formato de Aluno
        int matriculaBase = 1000; // Simula a geração de matrícula
        for (Map.Entry<String, String> entrada : dadosAntigos.entrySet()) {
            String idAntigo = entrada.getKey(); // Pode ser usado como parte da matrícula ou ignorado
            String nomeCompleto = entrada.getValue();
            // A lógica aqui pode ser mais complexa dependendo do mapeamento real
            alunosConvertidos.add(new Aluno(nomeCompleto, matriculaBase++));
        }
        System.out.println("Adaptador: Dados adaptados com sucesso.");
        return alunosConvertidos;
    }
}

// Cliente (Novo Sistema de Gestão Escolar)
class NovoSistemaGestaoEscolar {
    private ServicoDeDadosEscolar servicoDeDados;

    public NovoSistemaGestaoEscolar(ServicoDeDadosEscolar servicoDeDados) {
        this.servicoDeDados = servicoDeDados;
    }

    public void exibirAlunos() {
        System.out.println("\n--- Novo Sistema de Gestão Escolar: Exibindo Alunos ---");
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

        // O novo sistema usa o adaptador como se fosse o serviço de dados desejado
        NovoSistemaGestaoEscolar sistema = new NovoSistemaGestaoEscolar(adaptador);
        sistema.exibirAlunos();
    }
}
