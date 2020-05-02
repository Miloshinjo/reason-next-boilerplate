const path = require('path');
const bsconfig = require('./bsconfig.json');

const transpileModules = ['bs-platform'].concat(bsconfig['bs-dependencies']);
const withTM = require('next-transpile-modules')(transpileModules);

const config = {
  pageExtensions: ['jsx', 'js', 'bs.js'],
  experimental: {
    reactRefresh: true,
  },
  webpack: (config, options) => {
    const { isServer } = options;
    if (!isServer) {
      // We shim fs for things like the blog slugs component
      // where we need fs access in the server-side part
      config.node = {
        fs: 'empty',
        path: 'empty',
      };
    }

    // Here is the magic
    // We push our config into the resolve.modules array
    config.resolve.modules.push(path.resolve('./'));
    return config;
  },
};

module.exports = withTM(config);
