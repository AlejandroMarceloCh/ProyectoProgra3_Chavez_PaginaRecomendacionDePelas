// src/components/Sidebar.js
import React, { useState, useEffect } from 'react';
import { getRecommendations, getWatchLater } from '../api/movies';
import '../styles/Sidebar.css';

const Sidebar = () => {
    const [activeTab, setActiveTab] = useState('recommendations');
    const [recommendations, setRecommendations] = useState([]);
    const [watchLater, setWatchLater] = useState([]);

    useEffect(() => {
        if (activeTab === 'recommendations') {
            getRecommendations().then(setRecommendations).catch(() => setRecommendations([]));
        } else if (activeTab === 'watchLater') {
            getWatchLater().then(setWatchLater).catch(() => setWatchLater([]));
        }
    }, [activeTab]);

    const handleTabClick = (tab) => {
        setActiveTab(tab);
    };

    return (
        <div className="sidebar">
            <div className="sidebar-tabs">
                <button
                    onClick={() => handleTabClick('recommendations')}
                    className={activeTab === 'recommendations' ? 'active' : ''}
                >
                    Ver Películas Recomendadas
                </button>
                <button
                    onClick={() => handleTabClick('watchLater')}
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
