import React, { useState, useEffect } from 'react';
import { getRecommendations, getWatchLater } from '../api/movies';
import '../styles/Sidebar.css';

const Sidebar = () => {
  const [activeTab, setActiveTab] = useState('recommendations');
  const [recommendations, setRecommendations] = useState([]);
  const [watchLater, setWatchLater] = useState([]);

  useEffect(() => {
    const fetchData = async () => {
      try {
        if (activeTab === 'recommendations') {
          const data = await getRecommendations();
          setRecommendations(data);
        } else if (activeTab === 'watchLater') {
          const data = await getWatchLater();
          setWatchLater(data);
        }
      } catch (error) {
        console.error("Error al cargar datos del sidebar:", error);
      }
    };

    fetchData();
  }, [activeTab]);

  return (
    <div className="sidebar">
      <div className="sidebar-tabs">
        <button
          onClick={() => setActiveTab('recommendations')}
          className={activeTab === 'recommendations' ? 'active' : ''}
        >
          Ver Películas Recomendadas
        </button>
        <button
          onClick={() => setActiveTab('watchLater')}
          className={activeTab === 'watchLater' ? 'active' : ''}
        >
          Ver Más Tarde
        </button>
      </div>
      <div className="sidebar-content">
        {activeTab === 'recommendations' ? (
          recommendations.length > 0 ? (
            <ul>
              {recommendations.map((movie) => (
                <li key={movie.id}>
                  <span className="movie-title">{movie.title}</span>
                </li>
              ))}
            </ul>
          ) : (
            <p>No hay películas recomendadas disponibles.</p>
          )
        ) : (
          watchLater.length > 0 ? (
            <ul>
              {watchLater.map((movie) => (
                <li key={movie.id}>
                  <span className="movie-title">{movie.title}</span>
                </li>
              ))}
            </ul>
          ) : (
            <p>No hay películas en la lista de "Ver Más Tarde".</p>
          )
        )}
      </div>
    </div>
  );
};

export default Sidebar;
