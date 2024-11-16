// src/pages/HomePage.js
import React, { useEffect, useState } from 'react';
import MovieList from '../components/MovieList';
import { getRecommendations } from '../api/movies'; // Importamos correctamente

const HomePage = () => {
  const [recommendations, setRecommendations] = useState([]);

  useEffect(() => {
    const fetchRecommendations = async () => {
      const movies = await getRecommendations();
      setRecommendations(movies);
    };
    
    fetchRecommendations();
  }, []);

  return (
    <div className="HomePage">
      <h1>Películas Recomendadas</h1>
      <MovieList movies={recommendations} />
    </div>
  );
};

export default HomePage;
