const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const GenerateJsonPlugin = require('generate-json-webpack-plugin')
const outputDir = path.join(__dirname, 'build/');
const merge = require('webpack-merge')

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: {
    script: './src/Script.bs.js',
    index: './src/Index.bs.js'
  },
  mode: isProd ? 'production' : 'development',
  output: {
    path: outputDir,
    filename: '[name].bs.js'
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: 'src/index.html',
      inject: false
    }),
    new GenerateJsonPlugin(
        'manifest.json',
      merge(require('./manifest.json')),
      )
  ],
};
