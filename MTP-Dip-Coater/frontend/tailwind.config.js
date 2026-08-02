/** @type {import('tailwindcss').Config} */
export default {
  content: [
    "./index.html",
    "./src/**/*.{js,ts,jsx,tsx}",
  ],
  theme: {
    extend: {
      colors: {
        // Aesthetic color palette for premium design
        brand: {
          50: '#f5f7fa',
          100: '#eaeef4',
          200: '#d0daf1',
          300: '#a6bde7',
          400: '#7599da',
          500: '#4f75cb',
          600: '#3c5cb6',
          700: '#314a9a',
          800: '#2c3f7e',
          900: '#283769',
        }
      }
    },
  },
  plugins: [],
}
