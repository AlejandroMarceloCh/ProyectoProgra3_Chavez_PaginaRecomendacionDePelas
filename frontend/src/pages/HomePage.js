import React, { useEffect, useState } from 'react';
import MovieList from '../components/MovieList';
import { getRecommendations } from '../api/movies'; // Importamos correctamente

const HomePage = () => {
  const [recommendations, setRecommendations] = useState([]);

  // Obtener las recomendaciones al cargar la página
  useEffect(() => {
    const fetchRecommendations = async () => {
      try {
        const movies = await getRecommendations(); // Llama al backend
        setRecommendations(movies); // Actualiza el estado con las recomendaciones
      } catch (error) {
        console.error("Error al obtener recomendaciones:", error);
      }
    };

    fetchRecommendations();
  }, []);

  return (
    <div className="HomePage">
      <h1>Películas Recomendadas</h1>
      <MovieList movies={recommendations} /> {/* Renderiza las películas */}
    </div>
  );
};

export default HomePage;
