module.exports = {
  theme: {
    extend: {},
    /* We override the default font-families with our own default prefs  */
    fontFamily: {
      sans: [
        'Quicksand',
        'SF Pro Text',
        'Roboto',
        '-apple-system',
        'BlinkMacSystemFont',
        'Helvetica Neue',
        'Arial',
        'sans-serif',
      ],
      serif: [
        'Georgia',
        '-apple-system',
        'BlinkMacSystemFont',
        'Helvetica Neue',
        'Arial',
        'sans-serif',
      ],
      mono: [
        'Menlo',
        'Monaco',
        'Consolas',
        'Roboto Mono',
        'SFMono-Regular',
        'Segoe UI',
        'Courier',
        'monospace',
      ],
    },
    rotate: {
      '-315': '-315deg',
      '-180': '-180deg',
      '-135': '-135deg',
      '-90': '-90deg',
      '-45': '-45deg',
      '0': '0',
      '45': '45deg',
      '90': '90deg',
      '135': '135deg',
      '180': '180deg',
      '270': '270deg',
      '315': '315deg',
    },
  },
  variants: {
    width: ['responsive'],
  },
  plugins: [],
};
