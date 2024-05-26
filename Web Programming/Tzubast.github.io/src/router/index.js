import { createRouter, createWebHistory } from 'vue-router'
import HomeView from '../views/Calc.vue'
import 'font-awesome/css/font-awesome.css';


const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'home',
      component: HomeView
    }
  ]
})

export default router
