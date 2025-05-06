import React from 'react'
import { useEffect, useState } from "react";
import axios from "axios";
import { Howl } from "howler";

export default function App() {
  const [radio, setRadio] = useState(null);
  const [sound, setSound] = useState(null);
  const [isPlaying, setIsPlaying] = useState(false);

  const fetchRandomRadio = async () => {
    try {
      const { data } = await axios.get(
        "https://de1.api.radio-browser.info/json/stations/topclick/100"
      );
      const randomStation = data[Math.floor(Math.random() * data.length)];
      setRadio(randomStation);
    } catch (error) {
      console.error("Erro ao buscar rádio", error);
    }
  };

  const playRadio = () => {
    if (sound) sound.stop(); // Para rádio anterior

    const newSound = new Howl({
      src: [radio.url_resolved],
      html5: true,
      format: ["mp3", "aac"],
      onend: () => setIsPlaying(false),
      onplay: () => setIsPlaying(true),
      onloaderror: (_, err) => {
        console.error("Erro ao carregar rádio:", err);
        fetchRandomRadio(); // tenta outra
      }
    });

    setSound(newSound);
    newSound.play();
  };

  useEffect(() => {
    fetchRandomRadio();
  }, []);

  useEffect(() => {
    if (radio) playRadio();
  }, [radio]);

  return (
    <div className="min-h-screen bg-gray-900 text-white flex flex-col items-center justify-center p-4">
      <h1 className="text-4xl font-bold mb-4">🌐 Vamos escutar uma musiquinha?</h1>

      {radio ? (
        <div className="bg-gray-800 p-6 rounded-lg shadow-lg text-center">
          <h2 className="text-2xl font-semibold mb-2">{radio.name}</h2>
          <p className="text-sm text-gray-300">{radio.country} - {radio.language}</p>
          <button
            onClick={fetchRandomRadio}
            className="mt-6 bg-blue-600 hover:bg-blue-700 text-white font-semibold px-4 py-2 rounded"
          >
            Trocar Rádio 🔀
          </button>
        </div>
      ) : (
        <p>Carregando rádio...</p>
      )}

      {isPlaying && (
        <p className="mt-4 text-green-400">🎶 Tocando agora</p>
      )}
    </div>
  );
}
